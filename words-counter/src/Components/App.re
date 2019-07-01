[%bs.raw {|require('./App.css')|}]

[@react.component]
let make = () => {
  let (text, setText) = React.useState(() => "");
  let handleTextChange = e => e->ReactEvent.Form.target##value |> setText;
 
  <div className="App">
    <div className="header">
      <h3>{"Words Counter" |> ReasonReact.string}</h3>
    </div>
    <textarea
      placeholder="Express yourself..."
      value=text
      onChange=handleTextChange
    />
  </div>;
};
