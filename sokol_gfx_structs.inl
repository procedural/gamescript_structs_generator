// STRUCT(structName)
// MEMBER(memberType, memberName, memberCount)
// STRUCTEND()

#define SG_NUM_SHADER_STAGES       2
#define SG_NUM_INFLIGHT_FRAMES     2
#define SG_MAX_COLOR_ATTACHMENTS   4
#define SG_MAX_SHADERSTAGE_BUFFERS 8
#define SG_MAX_SHADERSTAGE_IMAGES  12
#define SG_MAX_SHADERSTAGE_UBS     4
#define SG_MAX_UB_MEMBERS          16
#define SG_MAX_VERTEX_ATTRIBUTES   16
#define SG_MAX_MIPMAPS             16
#define SG_MAX_TEXTUREARRAY_LAYERS 128
#define SG_CUBEFACE_NUM            6

STRUCT(sg_buffer)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_image)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_shader)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_pipeline)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_pass)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_context)
MEMBER(uint32_t, id, 1)
STRUCTEND()

STRUCT(sg_range)
MEMBER(const_void_p, ptr, 1)
MEMBER(size_t, size, 1)
STRUCTEND()

STRUCT(sg_color)
MEMBER(float, r, 1)
MEMBER(float, g, 1)
MEMBER(float, b, 1)
MEMBER(float, a, 1)
STRUCTEND()

STRUCT(sg_pixelformat_info)
MEMBER(bool, sample, 1)
MEMBER(bool, filter, 1)
MEMBER(bool, render, 1)
MEMBER(bool, blend, 1)
MEMBER(bool, msaa, 1)
MEMBER(bool, depth, 1)
STRUCTEND()

STRUCT(sg_features)
MEMBER(bool, instancing, 1)
MEMBER(bool, origin_top_left, 1)
MEMBER(bool, multiple_render_targets, 1)
MEMBER(bool, msaa_render_targets, 1)
MEMBER(bool, imagetype_3d, 1)
MEMBER(bool, imagetype_array, 1)
MEMBER(bool, image_clamp_to_border, 1)
MEMBER(bool, mrt_independent_blend_state, 1)
MEMBER(bool, mrt_independent_write_mask, 1)
STRUCTEND()

STRUCT(sg_limits)
MEMBER(int, max_image_size_2d, 1)
MEMBER(int, max_image_size_cube, 1)
MEMBER(int, max_image_size_3d, 1)
MEMBER(int, max_image_size_array, 1)
MEMBER(int, max_image_array_layers, 1)
MEMBER(int, max_vertex_attrs, 1)
MEMBER(int, gl_max_vertex_uniform_vectors, 1)
STRUCTEND()

STRUCT(sg_color_attachment_action)
MEMBER(sg_action, action, 1)
MEMBER(sg_color, value, 1)
STRUCTEND()

STRUCT(sg_depth_attachment_action)
MEMBER(sg_action, action, 1)
MEMBER(float, value, 1)
STRUCTEND()

STRUCT(sg_stencil_attachment_action)
MEMBER(sg_action, action, 1)
MEMBER(uint8_t, value, 1)
STRUCTEND()

STRUCT(sg_pass_action)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_color_attachment_action, colors, SG_MAX_COLOR_ATTACHMENTS)
MEMBER(sg_depth_attachment_action, depth, 1)
MEMBER(sg_stencil_attachment_action, stencil, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_bindings)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_buffer, vertex_buffers, SG_MAX_SHADERSTAGE_BUFFERS)
MEMBER(int, vertex_buffer_offsets, SG_MAX_SHADERSTAGE_BUFFERS)
MEMBER(sg_buffer, index_buffer, 1)
MEMBER(int, index_buffer_offset, 1)
MEMBER(sg_image, vs_images, SG_MAX_SHADERSTAGE_IMAGES)
MEMBER(sg_image, fs_images, SG_MAX_SHADERSTAGE_IMAGES)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_buffer_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(size_t, size, 1)
MEMBER(sg_buffer_type, type, 1)
MEMBER(sg_usage, usage, 1)
MEMBER(sg_range, data, 1)
MEMBER(const_char_p, label, 1)
MEMBER(uint32_t, gl_buffers, SG_NUM_INFLIGHT_FRAMES)
MEMBER(const_void_p, mtl_buffers, SG_NUM_INFLIGHT_FRAMES)
MEMBER(const_void_p, d3d11_buffer, 1)
MEMBER(const_void_p, wgpu_buffer, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_image_data)
MEMBER2D(sg_range, subimage, SG_CUBEFACE_NUM, SG_MAX_MIPMAPS)
STRUCTEND()

STRUCT(sg_image_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_image_type, type, 1)
MEMBER(bool, render_target, 1)
MEMBER(int, width, 1)
MEMBER(int, height, 1)
MEMBER(int, num_slices, 1)
MEMBER(int, num_mipmaps, 1)
MEMBER(sg_usage, usage, 1)
MEMBER(sg_pixel_format, pixel_format, 1)
MEMBER(int, sample_count, 1)
MEMBER(sg_filter, min_filter, 1)
MEMBER(sg_filter, mag_filter, 1)
MEMBER(sg_wrap, wrap_u, 1)
MEMBER(sg_wrap, wrap_v, 1)
MEMBER(sg_wrap, wrap_w, 1)
MEMBER(sg_border_color, border_color, 1)
MEMBER(uint32_t, max_anisotropy, 1)
MEMBER(float, min_lod, 1)
MEMBER(float, max_lod, 1)
MEMBER(sg_image_data, data, 1)
MEMBER(const_char_p, label, 1)
MEMBER(uint32_t, gl_textures, SG_NUM_INFLIGHT_FRAMES)
MEMBER(uint32_t, gl_texture_target, 1)
MEMBER(const_void_p, mtl_textures, SG_NUM_INFLIGHT_FRAMES)
MEMBER(const_void_p, d3d11_texture, 1)
MEMBER(const_void_p, d3d11_shader_resource_view, 1)
MEMBER(const_void_p, wgpu_texture, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_shader_attr_desc)
MEMBER(const_char_p, name, 1)
MEMBER(const_char_p, sem_name, 1)
MEMBER(int, sem_index, 1)
STRUCTEND()

STRUCT(sg_shader_uniform_desc)
MEMBER(const_char_p, name, 1)
MEMBER(sg_uniform_type, type, 1)
MEMBER(int, array_count, 1)
STRUCTEND()

STRUCT(sg_shader_uniform_block_desc)
MEMBER(size_t, size, 1)
MEMBER(sg_uniform_layout, layout, 1)
MEMBER(sg_shader_uniform_desc, uniforms, SG_MAX_UB_MEMBERS)
STRUCTEND()

STRUCT(sg_shader_image_desc)
MEMBER(const_char_p, name, 1)
MEMBER(sg_image_type, image_type, 1)
MEMBER(sg_sampler_type, sampler_type, 1)
STRUCTEND()

STRUCT(sg_shader_stage_desc)
MEMBER(const_char_p, source, 1)
MEMBER(sg_range, bytecode, 1)
MEMBER(const_char_p, entry, 1)
MEMBER(const_char_p, d3d11_target, 1)
MEMBER(sg_shader_uniform_block_desc, uniform_blocks, SG_MAX_SHADERSTAGE_UBS)
MEMBER(sg_shader_image_desc, images, SG_MAX_SHADERSTAGE_IMAGES)
STRUCTEND()

STRUCT(sg_shader_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_shader_attr_desc, attrs, SG_MAX_VERTEX_ATTRIBUTES)
MEMBER(sg_shader_stage_desc, vs, 1)
MEMBER(sg_shader_stage_desc, fs, 1)
MEMBER(const_char_p, label, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_buffer_layout_desc)
MEMBER(int, stride, 1)
MEMBER(sg_vertex_step, step_func, 1)
MEMBER(int, step_rate, 1)
STRUCTEND()

STRUCT(sg_vertex_attr_desc)
MEMBER(int, buffer_index, 1)
MEMBER(int, offset, 1)
MEMBER(sg_vertex_format, format, 1)
STRUCTEND()

STRUCT(sg_layout_desc)
MEMBER(sg_buffer_layout_desc, buffers, SG_MAX_SHADERSTAGE_BUFFERS)
MEMBER(sg_vertex_attr_desc, attrs, SG_MAX_VERTEX_ATTRIBUTES)
STRUCTEND()

STRUCT(sg_stencil_face_state)
MEMBER(sg_compare_func, compare, 1)
MEMBER(sg_stencil_op, fail_op, 1)
MEMBER(sg_stencil_op, depth_fail_op, 1)
MEMBER(sg_stencil_op, pass_op, 1)
STRUCTEND()

STRUCT(sg_stencil_state)
MEMBER(bool, enabled, 1)
MEMBER(sg_stencil_face_state, front, 1)
MEMBER(sg_stencil_face_state, back, 1)
MEMBER(uint8_t, read_mask, 1)
MEMBER(uint8_t, write_mask, 1)
MEMBER(uint8_t, ref, 1)
STRUCTEND()

STRUCT(sg_depth_state)
MEMBER(sg_pixel_format, pixel_format, 1)
MEMBER(sg_compare_func, compare, 1)
MEMBER(bool, write_enabled, 1)
MEMBER(float, bias, 1)
MEMBER(float, bias_slope_scale, 1)
MEMBER(float, bias_clamp, 1)
STRUCTEND()

STRUCT(sg_blend_state)
MEMBER(bool, enabled, 1)
MEMBER(sg_blend_factor, src_factor_rgb, 1)
MEMBER(sg_blend_factor, dst_factor_rgb, 1)
MEMBER(sg_blend_op, op_rgb, 1)
MEMBER(sg_blend_factor, src_factor_alpha, 1)
MEMBER(sg_blend_factor, dst_factor_alpha, 1)
MEMBER(sg_blend_op, op_alpha, 1)
STRUCTEND()

STRUCT(sg_color_state)
MEMBER(sg_pixel_format, pixel_format, 1)
MEMBER(sg_color_mask, write_mask, 1)
MEMBER(sg_blend_state, blend, 1)
STRUCTEND()

STRUCT(sg_pipeline_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_shader, shader, 1)
MEMBER(sg_layout_desc, layout, 1)
MEMBER(sg_depth_state, depth, 1)
MEMBER(sg_stencil_state, stencil, 1)
MEMBER(int, color_count, 1)
MEMBER(sg_color_state, colors, SG_MAX_COLOR_ATTACHMENTS)
MEMBER(sg_primitive_type, primitive_type, 1)
MEMBER(sg_index_type, index_type, 1)
MEMBER(sg_cull_mode, cull_mode, 1)
MEMBER(sg_face_winding, face_winding, 1)
MEMBER(int, sample_count, 1)
MEMBER(sg_color, blend_color, 1)
MEMBER(bool, alpha_to_coverage_enabled, 1)
MEMBER(const_char_p, label, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_pass_attachment_desc)
MEMBER(sg_image, image, 1)
MEMBER(int, mip_level, 1)
MEMBER(int, slice, 1)
STRUCTEND()

STRUCT(sg_pass_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(sg_pass_attachment_desc, color_attachments, SG_MAX_COLOR_ATTACHMENTS)
MEMBER(sg_pass_attachment_desc, depth_stencil_attachment, 1)
MEMBER(const_char_p, label, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()

STRUCT(sg_slot_info)
MEMBER(sg_resource_state, state, 1)
MEMBER(uint32_t, res_id, 1)
MEMBER(uint32_t, ctx_id, 1)
STRUCTEND()

STRUCT(sg_buffer_info)
MEMBER(sg_slot_info, slot, 1)
MEMBER(uint32_t, update_frame_index, 1)
MEMBER(uint32_t, append_frame_index, 1)
MEMBER(int, append_pos, 1)
MEMBER(bool, append_overflow, 1)
MEMBER(int, num_slots, 1)
MEMBER(int, active_slot, 1)
STRUCTEND()

STRUCT(sg_image_info)
MEMBER(sg_slot_info, slot, 1)
MEMBER(uint32_t, upd_frame_index, 1)
MEMBER(int, num_slots, 1)
MEMBER(int, active_slot, 1)
MEMBER(int, width, 1)
MEMBER(int, height, 1)
STRUCTEND()

STRUCT(sg_shader_info)
MEMBER(sg_slot_info, slot, 1)
STRUCTEND()

STRUCT(sg_pipeline_info)
MEMBER(sg_slot_info, slot, 1)
STRUCTEND()

STRUCT(sg_pass_info)
MEMBER(sg_slot_info, slot, 1)
STRUCTEND()

STRUCT(sg_gl_context_desc)
MEMBER(bool, force_gles2, 1)
STRUCTEND()

STRUCT(sg_metal_context_desc)
MEMBER(const_void_p, device, 1)
MEMBER(const_void_p, renderpass_descriptor_cb, 1)
MEMBER(const_void_p, renderpass_descriptor_userdata_cb, 1)
MEMBER(const_void_p, drawable_cb, 1)
MEMBER(const_void_p, drawable_userdata_cb, 1)
MEMBER(void_p, user_data, 1)
STRUCTEND()

STRUCT(sg_d3d11_context_desc)
MEMBER(const_void_p, device, 1)
MEMBER(const_void_p, device_context, 1)
MEMBER(const_void_p, render_target_view_cb, 1)
MEMBER(const_void_p, render_target_view_userdata_cb, 1)
MEMBER(const_void_p, depth_stencil_view_cb, 1)
MEMBER(const_void_p, depth_stencil_view_userdata_cb, 1)
MEMBER(void_p, user_data, 1)
STRUCTEND()

STRUCT(sg_wgpu_context_desc)
MEMBER(const_void_p, device, 1)
MEMBER(const_void_p, render_view_cb, 1)
MEMBER(const_void_p, render_view_userdata_cb, 1)
MEMBER(const_void_p, resolve_view_cb, 1)
MEMBER(const_void_p, resolve_view_userdata_cb, 1)
MEMBER(const_void_p, depth_stencil_view_cb, 1)
MEMBER(const_void_p, depth_stencil_view_userdata_cb, 1)
MEMBER(void_p, user_data, 1)
STRUCTEND()

STRUCT(sg_context_desc)
MEMBER(sg_pixel_format, color_format, 1)
MEMBER(sg_pixel_format, depth_format, 1)
MEMBER(int, sample_count, 1)
MEMBER(sg_gl_context_desc, gl, 1)
MEMBER(sg_metal_context_desc, metal, 1)
MEMBER(sg_d3d11_context_desc, d3d11, 1)
MEMBER(sg_wgpu_context_desc, wgpu, 1)
STRUCTEND()

STRUCT(sg_desc)
MEMBER(uint32_t, _start_canary, 1)
MEMBER(int, buffer_pool_size, 1)
MEMBER(int, image_pool_size, 1)
MEMBER(int, shader_pool_size, 1)
MEMBER(int, pipeline_pool_size, 1)
MEMBER(int, pass_pool_size, 1)
MEMBER(int, context_pool_size, 1)
MEMBER(int, uniform_buffer_size, 1)
MEMBER(int, staging_buffer_size, 1)
MEMBER(int, sampler_cache_size, 1)
MEMBER(sg_context_desc, context, 1)
MEMBER(uint32_t, _end_canary, 1)
STRUCTEND()
