class Transition:
    """A change from one state to a next"""

    def __init__(self, current_state, state_input, next_state):
        self.current_state = current_state
        self.state_input = state_input
        self.next_state = next_state

    def match(self, current_state, state_input):
        """Determines if the state and the input satisfies this transition relation"""
        return self.current_state == current_state and self.state_input == state_input

class FSM:
    """A basic model of computation"""

    def __init__(
            self,
            states=[],
            alphabet=[],
            accepting_states=[],
            initial_state=''):
        self.states = states
        self.alphabet = alphabet
        self.accepting_states = accepting_states
        self.initial_state = initial_state
        self.valid_transitions = False

    def add_transitions(self, transitions=[]):
        """Before we use a list of transitions, verify they only apply to our states"""
        for transition in transitions:
            if transition.current_state not in self.states:
                print(
                    'Invalid transition. {} is not a valid state'.format(
                        transition.current_state))
                return
            if transition.next_state not in self.states:
                print('Invalid transition. {} is not a valid state'.format)
                return
        self.transitions = transitions
        self.valid_transitions = True

    def __accept(self, current_state, state_input):
        """Looks to see if the input for the given state matches a transition rule"""
        # If the input is valid in our alphabet
        if state_input in self.alphabet:
            for rule in self.transitions:
                if rule.match(current_state, state_input):
                    return rule.next_state
            print('No transition for state and input')
            return None
        return None

    def accepts(self, sequence):
        """Process an input stream to determine if the FSM will accept it"""
        # Check if we have transitions
        if not self.valid_transitions:
            print('Cannot process sequence without valid transitions')

        print('Starting at {}'.format(self.initial_state))
        # When an empty sequence provided, we simply check if the initial state
        # is an accepted one
        if len(sequence) == 0:
            return self.initial_state in self.accepting_states

        # Let's process the initial state
        current_state = self.__accept(self.initial_state, sequence[0])
        if current_state is None:
            return False

        # Continue with the rest of the sequence
        for state_input in sequence[1:]:
            print('Current state is {}'.format(current_state))
            current_state = self.__accept(current_state, state_input)
            if current_state is None:
                return False

        print('Ending state is {}'.format(current_state))
        # Check if the state we've transitioned to is an accepting state
        return current_state in self.accepting_states