const X_CLASS = 'x'
const O_CLASS = 'o'
const WINNING_COMBOS = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
]
const cellElements = document.querySelectorAll('[js-cell]')
const board = document.getElementById('tictactoe')
const resultMessage = document.getElementById('result')
const resultMessageText = document.querySelector('[js-winning-msg]')
const restartButton = document.getElementById('restart-button')
let circleTurn

startGame()

restartButton.addEventListener('click', startGame)

function startGame(){
    circleTurn = false
    cellElements.forEach(cell => {
        cell.classList.remove(X_CLASS)
        cell.classList.remove(O_CLASS)
        cell.removeEventListener('click', handleClick)
        cell.addEventListener('click',handleClick, { once: true})
    })
    setBoardHoverClass()
    resultMessage.classList.remove('show')
}

function handleClick(e){
    const cell = e.target
    const curClass = circleTurn ? O_CLASS : X_CLASS
    //placeMark
    placeMark(cell,curClass)
    //Check for Win
    if(checkWin(curClass)){
        endGame(false)
    }
    else if(isDraw()){
        endGame(true)
    }
    else{
        swapTurn()
        setBoardHoverClass()
    }
}

function placeMark(cell, curClass){
    cell.classList.add(curClass)
}

function swapTurn(){
    circleTurn = !circleTurn
}

function setBoardHoverClass(){
    board.classList.remove(X_CLASS)
    board.classList.remove(O_CLASS)
    if(circleTurn){
        board.classList.add(O_CLASS)
    }
    else{
        board.classList.add(X_CLASS)
    }
}

function checkWin(curClass){
    return WINNING_COMBOS.some(combination => {
        return combination.every(index => {
            return cellElements[index].classList.contains(curClass)
        })
    })
}

function endGame(draw){
    if(draw){
        resultMessageText.innerText = 'Draw!'
    }
    else{
        resultMessageText.innerText = `${circleTurn ? "O" : "X"} Wins!`
    }
    resultMessage.classList.add('show')
}

function isDraw(){
    return [...cellElements].every(cell => {
        return cell.classList.contains(X_CLASS) || 
        cell.classList.contains(O_CLASS)
    })
}