[%bs.raw {|require("./App.css")|}];

[@react.component]
let make = _ => {
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;

  <div className="App">
    <header className="header">
      <h3> {"Words Counter" |> ReasonReact.string} </h3>
    </header>
    <main>
      <textarea
        placeholder="Express yourself..."
        value=text
        onChange=handleTextChange
      />
    </main>
  </div>;
};
