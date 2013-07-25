<?php
/**
 * @file
 * Admin pages for mhinstall_customer.module.
 */

/**
 * Form for adding or editing a mhinstall_customer entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_customer_form($form, &$form_state, $mhinstall_customer) {
  $form['label'] = array(
    '#title' => t('MH Install Customer ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_customer->label) ? $mhinstall_customer->label : '',
    '#description' => t('The label for this MH Install Customer entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_customer', $mhinstall_customer, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_customer->id) ? t('Update MH Install Customer') : t('Save MH Install Customer'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_customer_form.
 */
function mhinstall_customer_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_customer_form.
 */
function mhinstall_customer_form_submit($form, &$form_state) {
  $mhinstall_customer = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_customer->save();
  drupal_set_message(t('The entity @mhinstall_customer_label has been saved.', array('@mhinstall_customer_label' => $mhinstall_customer->label)));
  $form_state['redirect'] = 'admin/mh-install/data-types/mhinstall_customer';
}