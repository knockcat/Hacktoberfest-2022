import React, { useEffect, useState, useRef } from 'react'

function TodoForm(props) {
  const [input, setInput] = useState(props.edit ? props.edit.value : '')
  const handleSubmit = (e) => {
    e.preventDefault()

    props.onSubmit({
      id: Math.floor(Math.random() * 100),
      text: input,
    })
    setInput(' ')
  }
  const inputRef = useRef(null)
  useEffect(() => {
    inputRef.current.focus()
  })
  const handleChange = (e) => {
    setInput(e.target.value)
  }
  return (
    <form className="todo-form" onSubmit={handleSubmit}>
      <input
        type="text"
        placeholder="Add a Todo"
        value={input}
        name="text"
        onChange={handleChange}
        className="todo-input"
        ref={inputRef}
      />
      <button className="todo-btn"> Add Todo </button>
    </form>
  )
}
export default TodoForm
