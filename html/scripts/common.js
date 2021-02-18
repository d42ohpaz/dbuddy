export function createToast(titleText, bodyText, iconClass) {
    const container = $('<div></div>')
        .addClass('toast')
        .attr({
            role: 'alert',
            'data-autohide': 'false',
            'aria-live': 'assertive',
            'aria-atomic': 'true'
        });
    const header = $('<div></div>')
        .addClass('toast-header');
    const icon = $('<span></span>')
        .addClass(`icon-${iconClass}`);
    const title = $('<strong></strong>')
        .addClass('mr-auto');
    const close = $('<button type="button"></button>')
        .addClass('ml-2 mb-1 close')
        .attr({
            'data-dismiss': 'toast',
            'aria-label': 'Close',
        });
    const body = $('<div></div>')
        .addClass('toast-body');

    close.html('<span class="sr-hide">&times;</span>');
    title.text(titleText);
    body.html(bodyText);

    icon.appendTo(header);
    title.appendTo(header);
    close.appendTo(header);

    header.appendTo(container);
    body.appendTo(container);

    return container;
}

export default {
    createToast,
}
