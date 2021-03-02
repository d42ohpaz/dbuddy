import 'bootstrap';
import 'bootstrap/js/src/toast';
import 'spectrum-colorpicker2/dist/spectrum';

import { createToast } from './common.js';

let side_panel, form;
let color, name, url;
let counter = 0;

(function() {
    color = $('#color');
    form = $('form[name=dbuddy-form-calendars]');
    name = $('#name');
    side_panel = $('#side-panel');
    url = $('#url');

    const spectrum = color.spectrum.bind(color);

    spectrum({
        hideAfterPaletteSelect: "true",
        preferredFormat: "hex",
        showPalette: 'false',
        showPaletteOnly: "true",
        type: 'color',
    });

    form
        .find('[type=reset]').on('click', reset_form).end()
        .on('submit', (e) => {
            e.preventDefault();

            if (counter >= 8) {
                const toast = createToast('Error', 'Only 8 calendars are allowed.', 'icon-circle-minus');
                toast.prependTo($('#toasts'));
                toast.toast('show');
                return;
            }

            let action = form.attr('action');
            if (typeof action === 'undefined') {
                action = window.location.href;
            }

            const list = side_panel.find('ul');
            const template = form.data('editing') ? $(form.data('editing')) : $($('#side-panel-li').html());

            for (const el of [name, url, color]) {
                if (el.val().length === 0) {
                    const parent = el.parent();
                    parent.find('.form-text').show();
                    return;
                }

                el.next('.form-text').hide();
            }

            template
                .find('.swatch > span').css('background-color', color.val()).end()
                .find('input.color').val(color.val()).end()
                .find('.text').text(name.val()).end()
                .find('input.name').val(name.val()).end()
                .find('.text').attr('title', url.val()).end()
                .find('input.url').val(url.val()).end()
                .find('.edit').on('click', edit_calendar).end()
                .find('.remove').on('click', remove_calendar).end();

            template.appendTo(list);

            // AJAX request here
            $.ajax(action, {
                method: 'POST',
                data: form.serialize(),
            }).done(() => {
                if (!side_panel.hasClass('active')) {
                    side_panel.addClass('active');
                }

                // Because jQuery does not have a native method or event for resetting a form.
                form.find('[type=reset]').trigger('click');

                form.find('#add-edit .text').text('Add');
                form.find('#add-edit').removeClass('btn-success').addClass('btn-primary');

                counter++;
            });

            return false;
        });

})();

const edit_calendar = function() {
    const parent = $(this).parents('.media');

    const input_color = parent.find('input[name="color[]"]');
    const input_name = parent.find('input[name="name[]"]');
    const input_url = parent.find('input[name="url[]"]');

    form.data('editing', $(this).parents('.media').get(0));

    color.val(input_color.val());
    name.val(input_name.val());
    url.val(input_url.val());

    name.trigger('focus');

    form.find('#add-edit .text').text('Edit');
    form.find('#add-edit').removeClass('btn-primary').addClass('btn-success');
};

const remove_calendar = function() {
    const parent = $(this).parents('.media');
    parent.remove();
    counter--;

    if (side_panel.has('.media').length === 0) {
        side_panel.removeClass('active');
    }
};

const reset_form = (e) => {
    e.preventDefault();

    color.spectrum('set', '#000000');
    name.val('');
    url.val('');

    return false;
};

console.debug('Loaded calendars.js');
