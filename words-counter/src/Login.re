[%bs.raw {|require("./Login.css")|}];

[@react.component]
let make = () => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");

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
      </fieldset>
      <Button title="Login" category=Button.PRIMARY>
        {"Login" |> ReasonReact.string}
      </Button>
    </form>
  </div>;
};
