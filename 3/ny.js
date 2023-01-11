setTimeout(() => { // где-то в 23:40 Перелогинится, выбрать задачу и загрузить файл
    document.querySelector("input[type='submit']").click();
}, new Date("2022-01-01 00:00:00").getTime() - new Date().getTime());