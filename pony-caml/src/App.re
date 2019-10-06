[%bs.raw {|require('./App.css')|}];

[@react.component]
let make = () => {
  let (isModalVisible, setIsModalVisible) = React.useState(() => false);

  let handleButtonClick = _ => {
    setIsModalVisible(_ => true);
  };

  let onModalClose = _ => {
    setIsModalVisible(_ => false);
  };

  <main className="app">
    <h2> {"Parent Container" |> ReasonReact.string} </h2>
    <h3> {"This is just a demo container" |> ReasonReact.string} </h3>
    <button onClick=handleButtonClick>
      {"Open modal" |> ReasonReact.string}
    </button>
    {isModalVisible
       ? <Modal onModalClose>
           <Modal.Header> {"Header" |> ReasonReact.string} </Modal.Header>
           <Modal.Body> {"Body" |> ReasonReact.string} </Modal.Body>
           <Modal.Footer>
             <Modal.Footer.CloseBtn>
               {"Close" |> ReasonReact.string}
             </Modal.Footer.CloseBtn>
           </Modal.Footer>
         </Modal>
       : ReasonReact.null}
  </main>;
};
