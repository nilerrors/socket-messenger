const client_id = Date.now()

document.querySelector('#ws-id').textContent = client_id
const ws = new WebSocket(`ws://localhost:8000/ws/${client_id}`)

ws.onmessage = function (event) {
    if (
        event.data.length >= 25 &&
        event.data.slice(0, 26) === `Client #${client_id} says`
    )
        return

    const messages = document.getElementById('messages')
    const message = document.createElement('li')
    const content = document.createTextNode(event.data)
    message.appendChild(content)
    messages.appendChild(message)
}

function sendMessage(event) {
    const input = document.getElementById('messageText')
    ws.send(input.value)
    input.value = ''
    event.preventDefault()
}
