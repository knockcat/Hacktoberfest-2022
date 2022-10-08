let ath = document.getElementById("author")
let crypto = document.getElementById("crypto")
fetch("https://apis.scrimba.com/unsplash/photos/random?orientation=landscape&query=nature")
    .then(res => res.json())
    .then(data => {
        if (data.urls == undefined)
            throw Error();
        console.log(data)
        let img = data.urls.full;
        document.body.style.backgroundImage = `url(${img})`
        ath.innerText = `Photo By: ${data.user.name}`
    })
    .catch(err => {
        // console.log("Something went wrong!")

        document.body.style.backgroundImage = `url("https://images.unsplash.com/photo-1541280910158-c4e14f9c94a3?crop=entropy&cs=tinysrgb&fit=max&fm=jpg&ixid=MnwxNDI0NzB8MHwxfHJhbmRvbXx8fHx8fHx8fDE2NjI4MTg5NjI&ixlib=rb-1.2.1&q=80&w=1080")`
    })


fetch("https://api.coingecko.com/api/v3/coins/bitcoin", {
    method: "GET",
})
    .then(res => {
        if (!res.ok)
            throw Error("Something went wrong!")
        return res.json()
    })
    .then(data => {
        // console.log(data)
        let html = ""
        html = `<img src=${data.image.small}> <p>${data.name}</p>
   `
        crypto.innerHTML = html;
        document.getElementById("curr").innerHTML += `${data.market_data.current_price.usd}
    `
        document.getElementById("top").innerHTML += `${data.market_data.high_24h.usd}
    `
        document.getElementById("down").innerHTML += `${data.market_data.low_24h.usd}
    `
    })
    .catch(err => {
        console.log(err)
    })

function time() {
    let today = new Date();
    document.querySelector(".time").innerText = today.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })
}
setInterval(time, 1000);




navigator.geolocation.getCurrentPosition(position => {
    fetch(`https://apis.scrimba.com/openweathermap/data/2.5/weather?lat=${position.coords.latitude}&lon=${position.coords.longitude}&units=metric`)
        .then(res => {
            if (!res.ok) {
                throw Error("weather Data not available")
            }
            return res.json();
        })
        .then(data => {
            console.log(data)
            let html = ""
            console.log(data.weather[0].icon)
            html = `<img src= 'http://openweathermap.org/img/wn/${data.weather[0].icon}.png'>
        <p id="weather-temp">${Math.round(data.main.temp)}°C</p>
        <p class="weather-lower">${data.name}</p>
        <p class="weather-lower">${data.weather[0].description}</p>
        `
            document.querySelector("#weather").innerHTML = html

        })
        .catch(err => console.error(err))
});