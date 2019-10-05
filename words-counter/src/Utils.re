let countWordsInString = text => {
  let spacesRegEx = Js.Re.fromString("\s+");

  switch (text) {
  | "" => 0
  | noneEmptyText =>
    noneEmptyText
    |> Js.String.trim
    |> Js.String.splitByRe(spacesRegEx)
    |> Js.Array.length
  };
};
