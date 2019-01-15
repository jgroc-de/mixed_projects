function addStar(path, id)
{
	ggAjaxGet(path + id, printNotif, 'star');
}

function ggAjaxGet(path, callback, args)
{
    var request = new XMLHttpRequest();

    request.open('GET', path, true);
    request.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200)
        {
            callback(args);
        }
    };
    request.send();
}

function printNotif(args)
{
    var p = document.createElement('p');
    var div = document.createElement('div');
    var notif = document.getElementById('notif');
	var str = document.getElementById(args);
	var nbr;

	try {
		nbr = (Number(str.innerHTML) + 1);
		str.innerHTML = nbr;
	} catch (e) { }
    p.textContent = "Thx! ^^";
    div.appendChild(p);
        div.className = "w3-panel w3-round";
    if (args[1])
        div.classList.add('w3-green');
    else
        div.classList.add('w3-red');
    div.style.margin = "0";
    notif.appendChild(div);

    setTimeout(function() {
        notif.removeChild(div);
    }, 4500, notif, div);
}
