/* Behold! The login form. */

[%bs.raw {|require("./Login.css")|}];

type loginError =
  | EMAIL_NOT_FOUND
  | INVALID_PASSWORD
  | OTHER;

let loginError_of_string = str =>
  switch (str) {
  | "EMAIL_NOT_FOUND" => Some(EMAIL_NOT_FOUND)
  | "INVALID_PASSWORD" => Some(INVALID_PASSWORD)
  | _ => Some(OTHER)
  };

[@react.component]
let make = () => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  let (error, setError) = React.useState(() => None);

  let handleInputEmailChange = e =>
    ReactEvent.Form.target(e)##value |> setEmail;

  let handleInputPasswordChange = e =>
    ReactEvent.Form.target(e)##value |> setPassword;

  let handleFormSubmit = e => {
    ReactEvent.Form.preventDefault(e);
  };

  <div className="Login">
    <h2> {"Login Page" |> ReasonReact.string} </h2>
    <form onSubmit=handleFormSubmit>
      <fieldset>
        <label htmlFor="email" />
        <input
          type_="email"
          id="email"
          name="email"
          placeholder="Email"
          required=true
          value=email
          onChange=handleInputEmailChange
        />
        {switch (error) {
         | Some(EMAIL_NOT_FOUND) =>
           <div className="error">
             {{js| ⚠ email not found |js} |> ReasonReact.string}
           </div>
         | _ => ReasonReact.null
         }}
      </fieldset>
      <fieldset>
        <label htmlFor="password" />
        <input
          type_="password"
          id="password"
          name="password"
          placeholder="Password"
          required=true
          value=password
          onChange=handleInputPasswordChange
        />
        {switch (error) {
         | Some(INVALID_PASSWORD) =>
           <div className="error">
             {{js| ⚠ invalid password |js} |> ReasonReact.string}
           </div>
         | _ => ReasonReact.null
         }}
      </fieldset>
      <Button title="Login" category=Button.PRIMARY>
        {"Login" |> ReasonReact.string}
      </Button>
    </form>
  </div>;
};
