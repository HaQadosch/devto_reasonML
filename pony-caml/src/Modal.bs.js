// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as ReactDom from "react-dom";

((require("./css/Modal.css")));

function Modal(Props) {
  var children = Props.children;
  return ReactDom.createPortal(React.createElement("div", {
                  "aria-modal": true,
                  className: "modal-container",
                  role: "container"
                }, React.createElement("div", {
                      className: "modal-content"
                    }, children)), document.body);
}

var make = Modal;

export {
  make ,
  
}
/*  Not a pure module */
