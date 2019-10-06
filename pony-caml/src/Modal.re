[%bs.raw {|require("./css/Modal.css")|}];

[@bs.scope "document"] [@bs.val] external body: Dom.element = "body";

[@react.component]
let make = (~children) => ReactDOMRe.createPortal(
  <div className="modal-container" role="container" ariaModal=true>
    <div className="modal-content">children</div>
  </div>,
  body,
);