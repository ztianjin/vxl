#ifndef boxm2_processes_h_
#define boxm2_processes_h_

#include <bprb/bprb_func_process.h>
#include <bprb/bprb_macros.h>

//the init functions
DECLARE_FUNC_CONS(boxm2_load_scene_process);
DECLARE_FUNC_CONS(boxm2_modify_scene_appearance_process);
DECLARE_FUNC_CONS(boxm2_create_cache1_process);
DECLARE_FUNC_CONS(boxm2_create_cache_process);
DECLARE_FUNC_CONS(boxm2_create_scene_process);
DECLARE_FUNC_CONS(boxm2_write_scene_xml_process);
DECLARE_FUNC_CONS(boxm2_add_block_process);
DECLARE_FUNC_CONS(boxm2_export_textured_mesh_process);
DECLARE_FUNC_CONS(boxm2_export_mesh_process);
DECLARE_FUNC_CONS(boxm2_texture_mesh_process);
DECLARE_FUNC_CONS(boxm2_describe_scene_process);
DECLARE_FUNC_CONS(boxm2_create_stream_cache_process);
DECLARE_FUNC_CONS(boxm2_roi_init_process);
DECLARE_FUNC_CONS(boxm2_scene_illumination_info_process);
DECLARE_FUNC_CONS(boxm2_persp_cam_from_scene_process);
DECLARE_FUNC_CONS(boxm2_write_cache_process);
DECLARE_FUNC_CONS(boxm2_stream_cache_close_files_process);
DECLARE_FUNC_CONS(boxm2_compute_sun_affine_camera_process);
DECLARE_FUNC_CONS(boxm2_mask_sift_features_process);
DECLARE_FUNC_CONS(boxm2_bundle_to_scene_process);
DECLARE_FUNC_CONS(boxm2_clear_cache_process);
DECLARE_FUNC_CONS(boxm2_blob_change_detection_process);
DECLARE_FUNC_CONS(boxm2_blob_precision_recall_process);
DECLARE_FUNC_CONS(boxm2_scene_bbox_process);
DECLARE_FUNC_CONS(boxm2_transform_model_process);
DECLARE_FUNC_CONS(boxm2_create_scene_mask_process);
DECLARE_FUNC_CONS(boxm2_paint_mesh_process);
DECLARE_FUNC_CONS(boxm2_dem_to_xyz_process);
DECLARE_FUNC_CONS(boxm2_combine_expected_images_process);
DECLARE_FUNC_CONS(boxm2_scene_from_box_cams_process);
DECLARE_FUNC_CONS(boxm2_scene_from_nvm_txt_process);
DECLARE_FUNC_CONS(boxm2_compactify_mog6_view_process);
DECLARE_FUNC_CONS(boxm2_scene_statistics_process);

#if HAS_GEOTIFF
DECLARE_FUNC_CONS(boxm2_roi_init_geotiff_process);
#endif
DECLARE_FUNC_CONS(boxm2_scene_lvcs_process);
DECLARE_FUNC_CONS(boxm2_create_scene_and_blocks_process);
DECLARE_FUNC_CONS(boxm2_create_poly_scene_and_blocks_process);
DECLARE_FUNC_CONS(boxm2_add_aux_info_to_ply_process);
DECLARE_FUNC_CONS(boxm2_scene_kml_process);
DECLARE_FUNC_CONS(boxm2_scene_vrml_process);
DECLARE_FUNC_CONS(boxm2_distribute_scene_blocks_process);
DECLARE_FUNC_CONS(boxm2_ingest_convex_mesh_process);
DECLARE_FUNC_CONS(boxm2_lidar_to_xyz_process);
DECLARE_FUNC_CONS(boxm2_dem_to_xyz_process2);
DECLARE_FUNC_CONS(boxm2_initialize_ground_xyz_process);
DECLARE_FUNC_CONS(boxm2_label_to_xyz_process);
DECLARE_FUNC_CONS(boxm2_label_to_xyz_process2);
DECLARE_FUNC_CONS(boxm2_prune_scene_blocks_process);
DECLARE_FUNC_CONS(boxm2_prune_scene_blocks_by_dem_process);
DECLARE_FUNC_CONS(boxm2_load_mesh_process);
DECLARE_FUNC_CONS(boxm2_create_camera_from_kml_path_process);  // August 23, 2013 Yi Dong

DECLARE_FUNC_CONS(boxm2_ortho_geo_cam_from_scene_process);
DECLARE_FUNC_CONS(boxm2_import_point_cloud_process);  // August 23, 2013 Yi Dong
DECLARE_FUNC_CONS(boxm2_export_color_point_cloud_process);
//DECLARE_FUNC_CONS(boxm2_scene_fetch_alpha_process);
//DECLARE_FUNC_CONS(boxm2_create_crop_img_process);
#endif
