import 'bootstrap';
import 'bootstrap/js/src/toast';

import { createToast } from './common';

(function() {
    const form = $('form[name=dbuddy-form-wifi]');

    form.on('submit', function(e) {
        e.preventDefault();

        const ssid = $(this).find('#ssid');
        const password = $(this).find('#password');

        if (ssid.val() === '' || password === '') {
            const toast = createToast('WiFi Settings', 'You must provide a username/password.', 'exclamation-circle');

            toast.prependTo($('#toasts'));
            $('.toast').toast('show');

            if (ssid.val() === '') {
                ssid.parent().find('label').addClass('error');
                ssid.trigger('focus');
            }

            if (password.val() === '') {
                password.parent().find('label').addClass('error');
            }

            return false;
        }

        const location = window.location;
        const action = location.hostname === 'localhost'
            ? 'http://192.168.42.71/'
            : `${location.protocol}//${location.host}`;

        $.post(action, {
            ssid: ssid.val(),
            password: password.val(),
        }, function() {
            const toast = createToast('WiFi Settings', 'The WiFi SSID/Password have been saved.<br>It will take a moment for Desk Buddy to restart.', 'info-circle');

            toast.prependTo($('#toasts'));
            $('.toast').toast('show');

            ssid.val('');
            password.val('');
        }).fail(function() {
            const toast = createToast('WiFi Settings', 'There was a problem saving the WiFi SSID/Password.', 'exclamation-circle');

            toast.prependTo($('#toasts'));
            $('.toast').toast('show');
        });

        return false;
    });

    $('.icon-eye').on('click', function() {
        const checkbox = $(this).parents('label').prev('input[type=checkbox]');
        const password = $(this).parents('form').find('input#password');

        let newField;

        if (!checkbox.is(':checked')) {
            newField = $('<input type="text">');
        } else {
            newField = $('<input type="password">');
        }

        const attributes = password.prop('attributes');

        newField.val(password.val());
        $.each(attributes, function() {
            if (this.name === 'type')
                return;
            newField.attr(this.name, this.value);
        });

        password.replaceWith(newField);
    });
})();
console.debug('Loaded wifi.js');
