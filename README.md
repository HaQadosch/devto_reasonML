# devto_reasonML
https://dev.to/seif_ghezala/reasonml-for-production-react-apps-part-1-3nfk


# Page 1

## Set up

```bash
> npm i
> npm i bs-platform
> npx bsb -init words-counter -theme react-hooks
> cd words-counter/
> npm i
> npm start
```

In a shell:
```bash
> npm run build
```

In a second shell:
```bash
> npm run webpack
```

In a third shell:
```bash
> npm run server
```

Open a firefox tab to `localhost:8000`

This generates the project with react-hooks template.
This project becomes a [Reason-React](https://reasonml.github.io/reason-react/docs/en/installation.html "Init page") project

## Plugin

VS-Code [reasonML](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode "reason-vscode") is the official one.


## Iteration 1

Writing some text and storing the value in a variable.

### CSS 

To enable the CSS in webpack you need to 

  * install 2 packages: style-loader and css-loader 
  * add a rule in the module section of the webpack config
