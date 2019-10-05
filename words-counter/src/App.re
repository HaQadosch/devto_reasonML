[%bs.raw {|require("./App.css")|}];

[@react.component]
let make = _ => {
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;
  let wordsCountText =
    (text |> Utils.countWordsInString |> string_of_int) ++ " words";

  <div className="App">
    <header className="header">
      <h3> {"Words Counter" |> ReasonReact.string} </h3>
      <span> {ReasonReact.string(wordsCountText)} </span>
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
