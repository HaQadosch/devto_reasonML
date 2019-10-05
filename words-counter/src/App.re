[%bs.raw {|require("./App.css")|}];

module Times = {
  [@bs.module "./times.svg"] [@react.component]
  external make: (~height: string) => React.element = "default";
};

[@react.component]
let make = _ => {
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => ReactEvent.Form.target(e)##value |> setText;
  let handleClearClick = _ => setText(_ => "");
  let wordsCountText =
    (text |> Utils.countWordsInString |> string_of_int) ++ " words";

  <div className="App">
    <header>
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
    <footer>
      <Button
        title="Clear Text"
        onClick=handleClearClick
        disabled={text |> String.length === 0}>
        <Times height="20px" />
      </Button>
    </footer>
  </div>;
};
