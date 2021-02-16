const EleventyPluginMinifyHtml = require('@dyve/eleventy-plugin-minifyhtml');
module.exports = (config) => {
    config.addPlugin(EleventyPluginMinifyHtml, {
        minify: true,
    });

    return {
        dir: { input: 'html', output: 'data' },
        passthroughFileCopy: true,
        templateFormats: ["html", "css"],
    };
};
