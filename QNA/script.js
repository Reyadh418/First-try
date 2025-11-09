const form = document.getElementById("question-form");
const statusMessage = document.getElementById("status");

const gmailPattern = /^[a-zA-Z0-9._%+-]+@gmail\.com$/;

const setStatus = (message, type = "") => {
  statusMessage.textContent = message;
  statusMessage.classList.remove("error", "success");
  if (type) {
    statusMessage.classList.add(type);
  }
};

form.addEventListener("submit", (event) => {
  event.preventDefault();

  const fullName = form.fullName.value.trim();
  const gmail = form.gmail.value.trim();
  const question = form.question.value.trim();

  if (!fullName) {
    setStatus("Please provide your full name.", "error");
    form.fullName.focus();
    return;
  }

  if (!gmailPattern.test(gmail)) {
    setStatus("Enter a valid Gmail address (example@gmail.com).", "error");
    form.gmail.focus();
    return;
  }

  if (!question) {
    setStatus("Let us know what you'd like to ask.", "error");
    form.question.focus();
    return;
  }

  const subject = encodeURIComponent(`New Question from ${fullName}`);
  const bodyLines = [
    `Full Name: ${fullName}`,
    `Gmail: ${gmail}`,
    "",
    "Question:",
    question,
  ];
  const body = encodeURIComponent(bodyLines.join("\n"));

  const mailtoLink = `mailto:reyadhasan839279@gmail.com?subject=${subject}&body=${body}`;

  setStatus("Opening your email app to send the message…", "success");
  window.location.href = mailtoLink;
  form.reset();
});