const purgecss = require('@fullhuman/postcss-purgecss');
const cssnano = require('cssnano');
const autoprefixer = require('autoprefixer');
const purgeJs = require('purgecss-from-js');
const purgeHtml = require('purgecss-from-html');

const plugins = [
    autoprefixer,
    cssnano({ preset: 'default', }),
];

plugins.push(purgecss({
    content: [],
    css: ['data/**/*.css'],
    extractors: [
        {extractor: purgeJs, extensions: ['js']},
        {extractor: purgeHtml, extensions: ['html']},
    ]
}));

module.exports = {
  plugins
};
