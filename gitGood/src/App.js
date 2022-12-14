import "./App.css";
import Home from "./pages/Home";
import { useState, useEffect, useMemo } from "react";
import TerminalMobile from "./components/TerminalMobile";
import { useLockBodyScroll, useToggle } from "react-use";


const Modal = ({ setIsModalOpen, password, username }) => {
  const [inputValue, setinputValue] = useState("");

  const [isPassWordCorrect, setIsPasswordCorrect] = useState(true);

  const [locked, setLocked] = useToggle(false);

  const handleSubmit = () => {
    if (inputValue !== password) {
      setIsPasswordCorrect(false);
    } else {
      setIsPasswordCorrect(true);
      setIsModalOpen(false);
      setLocked(false)
    }
  };

  useLockBodyScroll(locked)

  return (
    <>
      <div className="modalback">
        <div className="modal">
          <p>password for 'https://{username}@github.com':</p>
          <p className="graypass">
            I knew you wouldn't remember it: {password}
          </p>
          <div>
            <input
              type="password"
              name="gitpass"
              onChange={(e) => {
                setinputValue(e.target.value);
              }}
            />
            <button
              className="btn"
              onClick={handleSubmit}
              disabled={inputValue === "" ? "true" : ""}
            >
              OK
            </button>
          </div>
          {!isPassWordCorrect ? (
            <p className="redpass">Wrong password!</p>
          ) : null}
        </div>
      </div>
    </>
  );
};

function App() {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [password, setPassword] = useState("")
  const [username, setUsername] = useState("")

  const appCallback = (homePushedValue) => {
    setIsModalOpen(homePushedValue);
  };

  const userPass = useMemo(()=> [
    ["bingChandler", "tripleNipple"],
    ["williamButcher", "thisIsDiabolical"],
    ["scottMichael", "littleKidLover"],
    ["tribbianiJoey", "howYouDoin"],
    ["schruteDwight", "bearsEatBeets"],
    ["homelander", "theRealHeroes"],
    ["snowJon", "iDunWannit"],
  ], [])

  const getUserPass = (arr) => {
    let random = Math.floor(Math.random() * arr.length);
    return arr[random]
  }

  useEffect(() => {
    let array = getUserPass(userPass)
    setUsername(array[0])
    setPassword(array[1])
  }, [userPass])

  return (
    <div className="App">
      {isModalOpen ? (
        <Modal
          setIsModalOpen={setIsModalOpen}
          password={password}
          username={username}
        />
      ) : null}
      <p className="para">
                  Hey, buddy! Are you trying to access this website on a phone?
                  How many times have you seen an actual dev using git on their
                  phone? Please, open it on a desktop. But hey, I'm generous,
                  and I didn't want the phone dwellers to go away with nothing.
                  So, go ahead and run{" "}
                  <code style={{ color: "green" }}>gg.resources</code> for some amazing git resources.
                </p>
                <TerminalMobile className="termapp"/>
      <Home
        className="homeApp"
        appCallback={appCallback}
        setIsModalOpen={setIsModalOpen}
        password={password}
        username={username}
      />
    </div>
  );
}

export default App;
