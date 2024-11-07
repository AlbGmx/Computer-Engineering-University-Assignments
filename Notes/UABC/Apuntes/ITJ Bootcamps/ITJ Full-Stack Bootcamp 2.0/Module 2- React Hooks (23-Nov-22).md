React Hooks are simple JavaScript functions that we can use to isolate the reusable part from a functional component. Hooks can be stateful and can manage side-effects.

# Standard built-in hooks

- useState
- useEffect
- useContext

# React Hooks

Let control states in the components

- useState → returns an array with 2 items [value, function to update variable]
    - `const [bool, setBool] = useState(true)`
- useEffect →
- useForm → from the react-hook-form library

  

### react-hook-form

Installation: `npm install react-hook-form`

react library for forms

Documentation: [react-hook-form.com/api/useform](http://react-hook-form.com/api/useform)

### Hook Form

Installation: `npm install @hookform/resolvers`

### Yup

Installation: `npm install yup`

creates schema for Form

Example:

```JavaScript
import * as yup from 'yup'

const productFormSchema = yup.object().shape({
	name: yup.string().required('You need to add a name'),
	price:  yup.int().required('You need to add a price'),
	imageUrl: yup.string()
})
```

# Que tranza, aqui se toman notas o k?

# Asi es krnal, echale ganitas no?