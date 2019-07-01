[%bs.raw {|require('./App.css')|}]

let countWordsInString = text => {
  let spacesRegex = Js.Re.fromString("\\s+")

  switch text {
  | "" => 0
  | nonEmpty => nonEmpty 
    |> Js.String.trim 
    |> Js.String.splitByRe(spacesRegex) 
    |> Js.Array.length
  };
};

[@react.component]
let make = () => {
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => e->ReactEvent.Form.target##value |> setText;
  let wordsCountText = (text |> countWordsInString |> string_of_int) ++ " words";
 
  <div className="App">
    <div className="header">
      <h3>{ "Words Counter" |> ReasonReact.string }</h3>
      <span>{ ReasonReact.string(wordsCountText) }</span>
    </div>
    <textarea
      placeholder="Express yourself..."
      value=text
      onChange=handleTextChange
    />
  </div>;
};
