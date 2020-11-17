function objectHasher(array, key, value) {
  const payload = Object.assign(
    {},
    ...array.map((state) => {
      if (!value) {
        return { [state[key]]: state };
      } else {
        return { [state[key]]: state[value] };
      }
    })
  );

  return payload;
};

export default objectHasher;
