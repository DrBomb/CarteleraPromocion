var htmlplugin = require("html-webpack-plugin")
module.exports = {
    entry:"./assets/entry.js",
    output:{
        path:"./data/",
        filename:"bundle.js"
    },
    devServer: {
        inline:true,
        contentBase: './data',
    },
    module:{
        loaders: [
            { test: /\.jpg$/, loader:"base64-image"},
            {
                test: /\.js$/,
                exclude: /node_modules/,
                loader: 'babel',
                query: {
                    presets: ['es2015','react']
                }
            },
            {test: /\.(woff|woff2)(\?v=\d+\.\d+\.\d+)?$/, loader: 'url?mimetype=application/font-woff'},
            {test: /\.ttf(\?v=\d+\.\d+\.\d+)?$/, loader: 'url?mimetype=application/octet-stream'},
            {test: /\.eot(\?v=\d+\.\d+\.\d+)?$/, loader: 'url?mimetype=application/vnd.ms-fontobject'},
            {test: /\.svg(\?v=\d+\.\d+\.\d+)?$/, loader: 'url?mimetype=image/svg+xml'}
        ]
    },
}
