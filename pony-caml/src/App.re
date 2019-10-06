[%bs.raw {|require('./css/App.css')|}];

[@react.component]
let make = () => {
  let (isModalVisible, setIsModalVisible) = React.useState(() => false);

  let handleButtonClick = _ => {
    setIsModalVisible(_ => true);
  };

  <main className="app">
    <h2>{"Parent Container" |> ReasonReact.string}</h2>
    <h3>{"This is just a demo container" |> ReasonReact.string}</h3>
    <button onClick=handleButtonClick >{"Open modal" |> ReasonReact.string}</button>
    { isModalVisible
        ? <Modal> <p>{"Foo" |> ReasonReact.string}</p> </Modal>
        : ReasonReact.null
    }
  </main>;
};