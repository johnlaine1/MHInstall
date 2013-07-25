<?php
/**
 * @file
 * Admin pages for mhinstall_home.module.
 */

/**
 * Form for adding or editing a mhinstall_home entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_home_form($form, &$form_state, $mhinstall_home) {
  $form['label'] = array(
    '#title' => t('mhinstall_home ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_home->label) ? $mhinstall_home->label : '',
    '#description' => t('The label for this mhinstall_home entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_home', $mhinstall_home, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_home->id) ? t('Update mhinstall_home') : t('Save mhinstall_home'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_home_form.
 */
function mhinstall_home_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_home_form.
 */
function mhinstall_home_form_submit($form, &$form_state) {
  $mhinstall_home = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_home->save();
  drupal_set_message(t('The entity @mhinstall_home_label has been saved.', array('@mhinstall_home_label' => $mhinstall_home->label)));
  $form_state['redirect'] = 'admin/mh-install/data-types/mhinstall_home';
}