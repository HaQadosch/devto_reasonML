[%bs.raw {|require("./Modal.css")|}];

[@bs.scope "document"] [@bs.val] external body: Dom.element = "body";

[@bs.scope "document"] [@bs.val]
external addKeyboardEventListener:
  (string, ReactEvent.Keyboard.t => unit) => unit =
  "addEventListener";

[@bs.scope "document"] [@bs.val]
external removeKeyboardEventListener:
  (string, ReactEvent.Keyboard.t => unit) => unit =
  "removeEventListener";

let modalContext = React.createContext(() => ());

module ContextProvider = {
  let makeProps = (~value, ~children: React.element, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(modalContext);
};

module Cross = {
  [@bs.module "./cross.svg"] [@react.component]
  external make: unit => React.element = "default";
};

[@react.component]
let make = (~children, ~onModalClose) => {
  let keyDownListener = e =>
    if (ReactEvent.Keyboard.keyCode(e) === 27) {
      onModalClose();
    };

  let effect = () => {
    addKeyboardEventListener("keydown", keyDownListener);
    Some(() => removeKeyboardEventListener("keyDown", keyDownListener));
  };

  React.useEffect(effect);

  ReactDOMRe.createPortal(
    <div className="modal-container" role="container" ariaModal=true>
      <div className="modal-content">
        <ContextProvider value=onModalClose> children </ContextProvider>
      </div>
    </div>,
    body,
  );
};

module Header = {
  [@react.component]
  let make = (~children) => {
    let onModalClose = React.useContext(modalContext);

    <header className="modal-header">
      children
      <button
        className="cross-btn"
        title="close Modal"
        onClick={_ => onModalClose()}>
        <Cross />
      </button>
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
      let onModalClose = React.useContext(modalContext);

      <button
        className="close-button"
        title="close modal"
        onClick={_ => onModalClose()}>
        children
      </button>;
    };
  };
};
