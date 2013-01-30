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

/**
 * Sort the seasons as requested by Luke.
 * 1. Spring
 * 2. Winter
 * 3. Autumn
 * 4. Summer
 */
function threedegrees_global_season_sort($a, $b) {
  $scores = array(
    'spring',
    'winter',
    'autumn',
    'summer',
  );
  $a_score = array_search(strtolower($a['name']), $scores);
  $b_score = array_search(strtolower($b['name']), $scores);

  if($a_score == $b_score) {
    return 0;
  }
  return ($a_score < $b_score) ? -1 : 1;
}

function threedegrees_global_taxonomy_build_news_structure() {
  $years_vocab = taxonomy_vocabulary_machine_name_load('year');
  $season_vocab = taxonomy_vocabulary_machine_name_load('season');

  $years_terms = threedegrees_global_taxonomy_get_terms_by_vid($years_vocab->vid);
  $season_terms = threedegrees_global_taxonomy_get_terms_by_vid($season_vocab->vid);

  uasort($season_terms, 'threedegrees_global_season_sort');

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

function threedegrees_global_get_recent_news_post() {
  $query = 'SELECT n.nid
    FROM `node` n
    WHERE n.type = \'news\'
    AND n.status = 1
    ORDER BY n.created ASC
    LIMIT 1';
      $result = db_query($query);
      $nid = NULL;
        foreach($result as $row){
          $nid = $row->nid;
        }
          return $nid;
}

