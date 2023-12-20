
function ToggleGroup( {options, className, active, setActive } ) {

    return (
        <div>
            {options.map(option => (
                <button className={active === option ? 'activeButton ' + className : 'button ' + className} onClick={ () => setActive(option)}>
                    {option}
                </button>
            ))}
        </div>
    );
}

export default ToggleGroup;
