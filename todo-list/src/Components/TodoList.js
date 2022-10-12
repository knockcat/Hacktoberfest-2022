// @ts-nocheck
//import { SettingsInputSvideoTwoTone } from '@material-ui/icons';
import React, { useState } from 'react'
import TodoForm from './TodoForm'
import Todo from './Todo'
function TodoList() {
  const [todos, setTodos] = useState([])
  const addTodo = (todo) => {
    const newTodo = [...todos, todo]
    setTodos(newTodo)
    console.log(newTodo)
  }
  const completeTodo = (id) => {
    let updatedTodo = todos.map((todo) => {
      if (todo.id === id) {
        todo.isComplete = !todo.isComplete
      }
      return todo
    })
    setTodos(updatedTodo)
  }
  const removeTodo = (id) => {
    const remove = [...todos].filter((todo) => todo.id !== id)
    setTodos(remove)
  }
  const updateTodo = (todoId, newvalue) => {
    setTodos((prev) =>
      prev.map((item) => (item.todoId === todoId ? newvalue : item)),
    )
  }
  return (
    <div>
      <TodoForm onSubmit={addTodo} />
      <Todo
        todos={todos}
        completeTodo={completeTodo}
        removeTodo={removeTodo}
        updateTodo={updateTodo}
      />
    </div>
  )
}
export default TodoList
