export default class Utils {
  constructor() {}

  //  object 인지 array 인지 검사
  //
  static isObject(obj: any): boolean {
    return Utils.getTypeNameOfString(obj) === '[object Object]' ? true : false;
  }

  static isArray(obj: any): boolean {
    return Utils.getTypeNameOfString(obj) === '[object Array]' ? true : false;
  }

  static size(any: any): number {
    if (typeof any === 'undefined' || any === null) return 0;

    if (Utils.isArray(any)) return any.length;
    if (Utils.isObject(any)) return Utils.objSize(any);

    if (typeof any.length !== 'undefined') return any.length;
    if (typeof any.size !== 'undefined') return any.size;

    return String(any).length;
  }

  static objSize(obj: any, justCheckIfNotEmpty?: boolean): number {
    let size = 0;

    justCheckIfNotEmpty = justCheckIfNotEmpty ?? false;

    for (const key in obj) {
      if (Object.hasOwnProperty.bind(obj)(key)) {
        size++;
        if (justCheckIfNotEmpty) return size;
      }
    }

    return size;
  }

  static getTypeNameOfString(any: string): string {
    if (typeof any === 'undefined' || any === null) return '';

    const getType = {};

    return getType.toString.call(any);
  }

  //  Object의 key와 value 를 분리하여 배열로 반환
  static getObjEntries(obj: any) {
    const entries: { keys: string[]; value: any[] } = { keys: [], value: [] };

    for (const key in obj) {
      if (Object.entries.bind(obj)(key)) {
        entries.keys.push(key);
        entries.value.push(obj[key]);
      }
    }

    return entries;
  }

  //  object array 에서 key 로 된 항목을 찾아서 arrary 로 만든다.
  //
  //  Utils.toArrayFromObjectArray( [ { id: "ab" }, { id: "cd" } ], "id" );
  //
  //  <result>
  //  [ "ab", "cd" ]
  //
  static toArrayFromObjectArray(objArray: any[], key?: string): any[] {
    const result: any[] = [];

    if (typeof key !== 'undefined') {
      objArray.forEach(obj => {
        if (!(key in obj)) return;
        if (obj[key] === null) return;
        result.push(obj[key]);
      });

      return result;
    } else {
      if (Utils.size(objArray) == 0) return result;
      if (Utils.isArray(objArray.at(0))) return objArray;

      return objArray.map(obj => Object.values(obj));
    }
  }

  // 배열을 랜덤으로 섞는 함수
  static shuffleArray = <T>(array: T[]): T[] => {
    const shuffled = [...array];
    for (let i = shuffled.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]];
    }
    return shuffled;
  };
}
