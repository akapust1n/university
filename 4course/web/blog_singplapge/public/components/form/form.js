import Block from "../block/block"
import  Button from "../button/button"

// import


export  default  class Form extends Block {

  /**
   * Конструктор класса Form
   */
  constructor(options = {data: {}}) {
    super('form');
    //'form/form.tmpl'
    this.data = options.data;
    this.template = window.fest[options.data.template];
    this.render();
  }

  /**
   * Обновляем HTML
   */
  render() {
    this._updateHtml();
  }

  /**
   * Обнуляем форму
   */
  reset() {
    this._el.reset();
  }

  /**
   * Обновить html компонента
   */
  _updateHtml() {
    this._el.innerHTML = this.template(this.data);
  }



  /**
   * Взять данные формы
   * @return {object}
   */
  getFormData() {
    let form = this._el;
    let elements = form.elements;
    let fields = {};

    Object.keys(elements).forEach(element => {
      let name = elements[element].name;
      let value = elements[element].value;

      if (!name) {
        return;
      }

      fields[name] = value;
    });

    return fields;
  }

}

