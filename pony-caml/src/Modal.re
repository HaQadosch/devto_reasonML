[%bs.raw {|require("./Modal.css")|}];

[@bs.scope "document"] [@bs.val] external body: Dom.element = "body";

module Cross = {
  [@bs.module "./cross.svg"] [@react.component]
  external make: unit => React.element = "default";
};

[@react.component]
let make = (~children) =>
  ReactDOMRe.createPortal(
    <div className="modal-container" role="container" ariaModal=true>
      <div className="modal-content"> children </div>
    </div>,
    body,
  );

module Header = {
  [@react.component]
  let make = (~children) => {
    <header className="modal-header">
      children
      <button className="cross-btn" title="close Modal"> <Cross /> </button>
    </header>;
  };
};

module Body = {
  [@react.component]
  let make = (~children) =>
    <article className="modal-body"> children </article>;
};

module Footer = {
  [@react.component]
  let make = (~children) => {
    <footer className="modal-footer"> children </footer>;
  };

  module CloseBtn = {
    [@react.component]
    let make = (~children) => {
      <button className="close-button" title="close modal"> children </button>;
    };
  };
};
