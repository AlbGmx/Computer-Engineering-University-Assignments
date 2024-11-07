“A JavaScript library for building user interfaces”

- Declarative
- Component Based
- Lean Once, Write Anywhere

# Creating a node.js app

Install node.js from ==[https://nodejs.org/en](https://nodejs.org/en)==

open folder in vscode and run

- npx create-react-app “appname”
- cd “appname”
- npm start

# JSX

Mix of JS with HTML-like syntax

# React Elements

Are the building blocks of React apps, it describes what you want to see on the screen

Are written just like regular HTML, you can write any valid HTML element in React

```JavaScript
return <div>Hello World</div>
return <h1>Hello World </h1>
return <button>Hello World</button>
```

- Element attributes
    - Uses camel case (className)

# React returning elements

# React Components

They let you split the UI into independent reusable pieces and think about each piece in isolation

Notes:

- Component names must be start with a capital letter
- Components, unlike JS functions must always return JSX

Components communicate over props

- Props:
    
    - work like parameter in functions
    - Are passed from parent to child component
    
    `npm install @mui/material @emotion/react @emotion/styled`
    
    `npm install @mui/icons-material`