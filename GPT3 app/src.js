const form = document.getElementById("coffee-order-form");
const statusDiv = document.getElementById("order-status");

form.addEventListener("submit", event => {
  event.preventDefault();

  const coffeeSelect = document.getElementById("coffee-select");
  const selectedCoffee = coffeeSelect.options[coffeeSelect.selectedIndex].value;

  const sizeRadios = document.getElementsByName("size");
  let selectedSize;
  for (const radio of sizeRadios) {
    if (radio.checked) {
      selectedSize = radio.value;
    }
  }

  const addMilkCheckbox = document.getElementById("add-milk");
  const addMilk = addMilkCheckbox.checked;

  const order = {
    coffee: selectedCoffee,
   size: selectedSize,
    addMilk
  };

  console.log(order);
  // Aquí podrías enviar la orden al servidor utilizando una petición HTTP (por ejemplo, usando fetch o XMLHttpRequest)

  statusDiv.innerHTML = "Su orden ha sido enviada. Por favor, pasar a recogerla cuando esté lista.";
});

