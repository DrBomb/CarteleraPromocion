import React from 'react';
import ReactDOM from 'react-dom';
var images = require('./images.js');
require('expose?$!expose?jQuery!jquery');
require("!bootstrap-webpack!./bootstrap.config.js");
require('react-logger');
class Foto extends React.Component {
    render(){
        return(<div className="col-md-2 col-sm-3 col-xs-6" onClick={this.handleClick.bind(this)}><img src={this.props.data} className="img-responsive" width="100%"/></div>);
    }
    handleClick(){
        $.ajax({
            url:"/",
            method:'POST',
            data:{
                index:this.props.index,
            }

        });
    }
}

class Fotos extends React.Component {
    render(){
        return (
                <div className="fotos">
            {this.props.data.map(function(entry,i){

                 return(<Foto data={entry} index={i} />);
            })}
            </div>
            );
        }
    request() {
        console.log(i);
    }
}
console.log("Hola");
ReactDOM.render(<Fotos data={images} />, document.getElementById("container"));
