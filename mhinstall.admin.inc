<?php
/**
 * @file
 * Admin pages for mhinstall.module.
 */

function mhinstall_admin_form($form, &$form_state) {
  $form['test'] = array(
    '#type' => 'markup',
    '#markup' => 'Brought to you by the "mhinstall_admin_form" function',
  );
  
  return $form;
}