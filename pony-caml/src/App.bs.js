// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Modal$ReactHooksTemplate from "./Modal.bs.js";

((require('./App.css')));

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
  var onModalClose = function (param) {
    return Curry._1(setIsModalVisible, (function (param) {
                  return false;
                }));
  };
  return React.createElement("main", {
              className: "app"
            }, React.createElement("h2", undefined, "Parent Container"), React.createElement("h3", undefined, "This is just a demo container"), React.createElement("button", {
                  onClick: handleButtonClick
                }, "Open modal"), match[0] ? React.createElement(Modal$ReactHooksTemplate.make, {
                    children: null,
                    onModalClose: onModalClose
                  }, React.createElement(Modal$ReactHooksTemplate.Header[/* make */0], {
                        children: "Header"
                      }), React.createElement(Modal$ReactHooksTemplate.Body[/* make */0], {
                        children: "Body"
                      }), React.createElement(Modal$ReactHooksTemplate.Footer[/* make */0], {
                        children: React.createElement(Modal$ReactHooksTemplate.Footer[/* CloseBtn */1][/* make */0], {
                              children: "Close"
                            })
                      })) : null);
}

var make = App;

export {
  make ,
  
}
/*  Not a pure module */