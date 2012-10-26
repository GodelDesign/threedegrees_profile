<?php

/**
 * @file
 * Defining reusable functions for use in this module
 */

function threedegrees_global_taxonomy_get_terms_by_vid($vid) {
  $query = 'SELECT term_data.tid, term_data.name FROM {taxonomy_term_data} term_data WHERE term_data.vid = :vid';
  $result = db_query($query, array(':vid' => $vid));
  $terms = array();
  foreach($result as $row) {
    $terms[$row->tid] = array(
      'tid' => $row->tid,
      'name' => $row->name,
    );
  }
  return $terms;
}

function threedegrees_global_taxonomy_build_news_structure() {
  $years_vocab = taxonomy_vocabulary_machine_name_load('year');
  $season_vocab = taxonomy_vocabulary_machine_name_load('season');

  $years_terms = threedegrees_global_taxonomy_get_terms_by_vid($years_vocab->vid);
  $season_terms = threedegrees_global_taxonomy_get_terms_by_vid($season_vocab->vid);

  dpm($years_terms);
  dpm($season_terms);
/*
Query to see how many nodes are in year X and season Y
SELECT n.nid, t_index_year.tid, t_index_season.tid
  FROM node n
  INNER JOIN taxonomy_index t_index_year ON t_index_year.nid = n.nid
  INNER JOIN taxonomy_index t_index_season ON t_index_season.nid = n.nid
  WHERE t_index_season.tid = 19
  AND t_index_year.tid = 21
 */

}
