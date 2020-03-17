const electron = require('electron')

console.log(process.versions)

function createWindow() {
  const w = new electron.BrowserWindow({
    width: 720,
    height: 450,
  })

  w.loadFile('src/index.html')
}

electron.app.whenReady().then(createWindow)
