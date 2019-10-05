[%bs.raw {|require("./Button.css")|}];

type categoryButton =
  | PRIMARY
  | SECONDARY;

let className_of_categoryButton = category =>
  "Button "
  ++ (
    switch (category) {
    | PRIMARY => "primary"
    | SECONDARY => "secondary"
    }
  );

[@react.component]
let make =
    (
      ~onClick,
      ~title: string,
      ~children: ReasonReact.reactElement,
      ~disabled=false,
      ~category=SECONDARY,
    ) =>
  <button
    onClick className={category |> className_of_categoryButton} title disabled>
    children
  </button>;
