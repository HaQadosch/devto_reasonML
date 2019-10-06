// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Modal$ReactHooksTemplate from "./Modal.bs.js";

((require('./css/App.css')));

function App(Props) {
  var match = React.useState((function () {
          return false;
        }));
  var setIsModalVisible = match[1];
  var handleButtonClick = function (param) {
    return Curry._1(setIsModalVisible, (function (param) {
                  return true;
                }));
  };
  return React.createElement("main", {
              className: "app"
            }, React.createElement("h2", undefined, "Parent Container"), React.createElement("h3", undefined, "This is just a demo container"), React.createElement("button", {
                  onClick: handleButtonClick
                }, "Open modal"), match[0] ? React.createElement(Modal$ReactHooksTemplate.make, {
                    children: React.createElement("p", undefined, "Foo")
                  }) : null);
}

var make = App;

export {
  make ,
  
}
/*  Not a pure module */
