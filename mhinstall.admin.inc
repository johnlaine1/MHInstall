<?php
/**
 * @file
 * Admin pages for mhinstall.module.
 */

/**
 * Form for adding or editing a mhinstall entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_form($form, &$form_state, $mhinstall) {
  $form['label'] = array(
    '#title' => t('MH Install ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall->label) ? $mhinstall->label : '',
    '#description' => t('The installation ID of this MH Install'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall', $mhinstall, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall->id) ? t('Update MH Install') : t('Save MH Install'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_form.
 */
function mhinstall_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_form.
 */
function mhinstall_form_submit($form, &$form_state) {
  $mhinstall = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall->save();
  drupal_set_message(t('The MH Install @mhinstall_label has been saved.', array('@mhinstall_label' => $mhinstall->label)));
  $form_state['redirect'] = 'admin/structure/mhinstall';
}