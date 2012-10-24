<?php
/**
 * @file
 * threedegrees_global.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function threedegrees_global_taxonomy_default_vocabularies() {
  return array(
    'project_type' => array(
      'name' => 'Project Type',
      'machine_name' => 'project_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
    'season' => array(
      'name' => 'Season',
      'machine_name' => 'season',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
  );
}
