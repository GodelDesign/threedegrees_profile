<?php
/**
 * @file
 * threedegrees_global.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function threedegrees_global_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'other_projects_block' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|project|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function threedegrees_global_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'other_projects';
  $ds_field->label = 'Other projects';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|projects-block_1',
    'block_render' => '3',
  );
  $export['other_projects'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'other_projects_block';
  $ds_field->label = 'Other Projects Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'views|projects-block_1',
    'block_render' => '2',
  );
  $export['other_projects_block'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function threedegrees_global_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_long_title_tagline',
      ),
      'left' => array(
        0 => 'field_main_image',
        1 => 'field_additional_images',
      ),
      'right' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'field_long_title_tagline' => 'header',
      'field_main_image' => 'left',
      'field_additional_images' => 'left',
      'body' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_long_title_tagline',
      ),
      'left' => array(
        0 => 'field_main_image',
        1 => 'field_additional_images',
      ),
      'right' => array(
        0 => 'body',
      ),
      'footer' => array(
        0 => 'other_projects_block',
      ),
    ),
    'fields' => array(
      'field_long_title_tagline' => 'header',
      'field_main_image' => 'left',
      'field_additional_images' => 'left',
      'body' => 'right',
      'other_projects_block' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|project|full'] = $ds_layout;

  return $export;
}
