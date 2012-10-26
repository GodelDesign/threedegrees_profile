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

function threedegrees_global_taxonomy_check_year_season_results($year, $season) {
  $results = FALSE;
  $query = 'SELECT n.nid, t_index_year.tid, t_index_season.tid
    FROM node n
    INNER JOIN taxonomy_index t_index_year ON t_index_year.nid = n.nid
    INNER JOIN taxonomy_index t_index_season ON t_index_season.nid = n.nid
    WHERE t_index_season.tid = :season
    AND t_index_year.tid = :year';
  $result = db_query
    ($query,
    array(
      ':season' => $season,
      ':year' => $year,
    )
  );
  if($result->rowCount()) {
    $results = TRUE;
  }
  return $results;
}

function threedegrees_global_taxonomy_build_news_structure() {
  $years_vocab = taxonomy_vocabulary_machine_name_load('year');
  $season_vocab = taxonomy_vocabulary_machine_name_load('season');

  $years_terms = threedegrees_global_taxonomy_get_terms_by_vid($years_vocab->vid);
  $season_terms = threedegrees_global_taxonomy_get_terms_by_vid($season_vocab->vid);

  $structure = array();
  foreach($years_terms as $year) {
    foreach($season_terms as $season) {
      if(threedegrees_global_taxonomy_check_year_season_results($year['tid'], $season['tid'])) {
        $structure[$year['name']][] = $season['name'];
      }
    }
  }

  return $structure;
}
