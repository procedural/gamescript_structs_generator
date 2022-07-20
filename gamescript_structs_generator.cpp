// cl gamescript_structs_generator.cpp && gamescript_structs_generator.exe > structs.txt
// c++ -std=c++14 gamescript_structs_generator.cpp -o gamescript_structs_generator && ./gamescript_structs_generator > structs.txt

#include <map>
#include <string>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <assert.h>

typedef struct StructureMember {
  std::string type;
  std::string name;
  uint64_t    count1;
  uint64_t    count2;
} StructureMember;

typedef struct Structure {
  std::vector<StructureMember> members;
} Structure;

std::map<std::string, Structure> gStructs;

int TypeIsStruct(std::string type) {
  Structure structure = gStructs[type];
  return structure.members.size() > 0 ? 1 : 0;
}

int StructureHasOnlyPlainMemberTypes(Structure structure) {
  for (const auto & member : structure.members) {
    if (TypeIsStruct(member.type) == 1) {
      return 0;
    }
  }
  return 1;
}

int MemberTypeIsString(std::string memberType) {
  if (
    memberType == std::string("const_char_p")
  )
  {
    return 1;
  }
  return 0;
}

std::string MemberTypeToScriptType(std::string memberType) {
  if (MemberTypeIsString(memberType) == 1) {
    return std::string("String");
  }
  return std::string("Number");
}

std::string MemberTypeToPointerSetCall(std::string memberType) {
  return std::string("pointerSetAtOffset_") + memberType;
}

typedef struct ParentStructure {
  std::string type;
  std::string name;
  uint64_t    index;
} ParentStructure;

typedef enum PrintMode {
  PRINT_MODE_NONE          = 0,
  PRINT_MODE_FN_PARAMETERS = 1,
  PRINT_MODE_FN_BODY       = 2,
} PrintMode;

void PrintStructureMembersRecursively(std::vector<ParentStructure> parentStructs, PrintMode printMode, uint64_t parentStructCount, std::string prependToName, Structure structure) {
  for (const auto & member : structure.members) {
    if (TypeIsStruct(member.type) == 1) {
      std::string memberName = member.name;
      if (prependToName != std::string("")) {
        memberName[0] = memberName[0] & 0xDF; // Capitalize the first letter.
      }
      if (StructureHasOnlyPlainMemberTypes(gStructs[member.type]) == 1) {
        // Leaf structure, printing arrays then.
        std::string newPrependToName = prependToName + memberName;
        parentStructs.push_back({member.type, member.name, (uint64_t)-1});
        PrintStructureMembersRecursively(parentStructs, printMode, (member.count1*member.count2), newPrependToName, gStructs[member.type]);
        parentStructs.pop_back();
      } else {
        std::string structIndex = std::string("");
        for (size_t i = 0; i < (member.count1*member.count2); i += 1) {
          if ((member.count1*member.count2) > 1) {
            structIndex = std::to_string(i);
          }      
          std::string newPrependToName = prependToName + memberName + structIndex;
          parentStructs.push_back({member.type, member.name, i});
          PrintStructureMembersRecursively(parentStructs, printMode, 1, newPrependToName, gStructs[member.type]);
          parentStructs.pop_back();
        }
      }
    } else {
      assert(!(parentStructCount > 1 && (member.count1*member.count2) > 1)); // Can't handle this case yet.
      std::string memberName = member.name;
      if (prependToName != std::string("")) {
        memberName[0] = memberName[0] & 0xDF; // Capitalize the first letter.
      }
      std::string name = prependToName + memberName;
      uint64_t memberCount = (parentStructCount > 1 ? parentStructCount : 0) + ((member.count1*member.count2) > 1 ? (member.count1*member.count2) : 0);

      if (printMode == PRINT_MODE_FN_PARAMETERS && false) {
        std::string countComment = " // [";
        countComment += std::to_string(memberCount);
        countComment += "]";
        printf("  %s %s,%s\n", member.type.c_str(), name.c_str(), memberCount > 1 ? countComment.c_str() : "");
      }

      if (printMode == PRINT_MODE_FN_PARAMETERS && true) {
        std::string comment = " // ";
        comment += MemberTypeToScriptType(member.type);
        comment += " ";
        comment += name;
        if (memberCount > 1) {
          comment += " ";
          comment += "[";
          comment += std::to_string(memberCount);
          comment += "]";
        }
        printf("  %s,%s\n", name.c_str(), comment.c_str());
      }

      if (printMode == PRINT_MODE_FN_BODY && true) {
        if (memberCount > 1) {
          printf("  for (var i = 0; i < len(%s); i += 1) {\n", name.c_str());
          // Copy-pasted with a few tweaks
          {
            printf("    %s(structPointer, ", MemberTypeToPointerSetCall(member.type).c_str());
            for (size_t i = 0; i < parentStructs.size() - 1; i += 1) {
              printf("%s_offsetof_%s + (%s_sizeof * %s) + ", parentStructs[i].type.c_str(), parentStructs[i + 1].name.c_str(), parentStructs[i + 1].type.c_str(), parentStructs[i + 1].index == -1 ? "i" : std::to_string(parentStructs[i + 1].index).c_str());
            }
            printf("%s_offsetof_%s + (%s_sizeof * %s)", parentStructs.back().type.c_str(), member.name.c_str(), member.type.c_str(), (member.count1*member.count2) > 1 ? "i" : "0");
            printf(", ");
            printf("%s[i]", name.c_str());
            printf(")\n");
          }
          printf("  }\n", std::to_string(memberCount));
        } else {
          // Copy-paste
          {
            printf("  %s(structPointer, ", MemberTypeToPointerSetCall(member.type).c_str());
            for (size_t i = 0; i < parentStructs.size() - 1; i += 1) {
              printf("%s_offsetof_%s + (%s_sizeof * %s) + ", parentStructs[i].type.c_str(), parentStructs[i + 1].name.c_str(), parentStructs[i + 1].type.c_str(), parentStructs[i + 1].index == -1 ? "0" : std::to_string(parentStructs[i + 1].index).c_str());
            }
            printf("%s_offsetof_%s", parentStructs.back().type.c_str(), member.name.c_str());
            printf(", ");
            printf("%s", name.c_str());
            printf(")\n");
          }
        }
      }
    }
  }
}

int main() {
  std::string currentStructName;

#define STRUCT(NAME) currentStructName = #NAME;
#define STRUCTEND()
#define MEMBER(TYPE, NAME, COUNT_1)            { StructureMember member = {}; member.type = #TYPE; member.name = #NAME; member.count1 = COUNT_1; member.count2 = 1;       gStructs[currentStructName].members.push_back(member); }
#define MEMBER2D(TYPE, NAME, COUNT_1, COUNT_2) { StructureMember member = {}; member.type = #TYPE; member.name = #NAME; member.count1 = COUNT_1; member.count2 = COUNT_2; gStructs[currentStructName].members.push_back(member); }

#include "structs.inl"

  // Now generate struct script functions
  {
    for (const auto & structPair : gStructs) {
      std::string structureType = structPair.first;
      Structure   structure     = structPair.second;

      if (TypeIsStruct(structureType) == 0) {
        continue;
      }

      std::vector<ParentStructure> parentStructs;
      parentStructs.push_back({structureType, std::string(""), (uint64_t)-1});

      printf("fn %s(\n", structureType.c_str());
      printf("  structPointer, // Number structPointer\n");
      PrintStructureMembersRecursively(parentStructs, PRINT_MODE_FN_PARAMETERS, 1, std::string(""), structure);
      printf("  setTo0 // Number setTo0\n");
      printf(")\n");
      printf("{\n");
      PrintStructureMembersRecursively(parentStructs, PRINT_MODE_FN_BODY, 1, std::string(""), structure);
      printf("}\n");
      printf("\n");
    }
  }

  return 0;
}
