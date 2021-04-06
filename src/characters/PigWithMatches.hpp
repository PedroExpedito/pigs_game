#ifndef __PIG_WITH_MATCHES_HPP
#define __PIG_WITH_MATCHES_HPP

#include <characters/IGameCharacter.hpp>

#include <Animation.hpp>
#include <Vector2D.hpp>

#include <random.hpp>
#include <sdl_wrappers.hpp>

class PigWithMatches : public IGameCharacter {
public:
    static auto constexpr IDLE_ANIMATION = 0;
    static auto constexpr ACTIVATE_CANNON = 1;
    static auto constexpr PREPARE_NEXT_MATCH = 2;
    static auto constexpr MATCH_ON_HAND = 3;

    static auto constexpr DEFAULT_THINK_TIMEOUT = 500.0;

    static auto constexpr collision_size = Vector2D<int>{18, 18};

    PigWithMatches(SDL_Renderer* renderer, double pos_x, double pos_y, int face, Cannon& cannon)
        : face(face)
        , position{pos_x, pos_y}
        , old_position{pos_x, pos_y}
        , velocity{0.0, 0.0}
        , renderer(renderer)
        , spritesheet(load_media("assets/sprites/pig_with_match96x96.png", renderer))
        , think_timeout(PigWithMatches::DEFAULT_THINK_TIMEOUT)
        , start_attack(false)
        , preparing_next_match(false)
        , cannon(cannon)
    {
        auto register_animation = [&](int id, std::vector<std::tuple<int, int>> const& frames, double time) {
            this->animations.insert(std::make_pair(id, Animation(this->spritesheet, frames, 96, 96, time)));
        };
        
        register_animation(
            PigWithMatches::IDLE_ANIMATION,
            {
                {0, 3},
                {1, 3},
                {2, 3},
                {1, 3},
            },
            200.
        );
        register_animation(
            PigWithMatches::ACTIVATE_CANNON, 
            {
                {0, 0},
                {1, 0},
                {2, 0},
                {0, 1},
                {1, 1},
                {2, 1},
                {0, 2},
                {1, 2},
                {1, 2},
                {1, 2},
                {1, 2},
                {2, 2},
            },
            100.
        );
        this->animations.at(PigWithMatches::ACTIVATE_CANNON).set_on_finish_animation_callback([this]() {
            this->start_attack = false;
            this->cannon.trigger_attack();
        });
    }

    void set_position(double x, double y) override
    {
        this->position.x = x;
        this->position.y = y;
    }

    Vector2D<double> get_position() const override
    {
        return this->position;
    }
    
    void set_velocity(double x, double y) override
    {
        this->velocity.x = x;
        this->velocity.y = y;
    }

    Vector2D<double> get_velocity() const override
    {
        return this->velocity;
    }
    
    CollisionRegionInformation get_collision_region_information() const override
    {
        return CollisionRegionInformation(this->position, this->old_position, this->collision_size);
    }
    
    void handle_collision(CollisionType const& type, CollisionSide const& side) override {}
    void on_after_collision() override {}
    
    void update(double elapsedTime) override
    {
        this->think(elapsedTime);

        // Position setup
        this->old_position = this->position;
        this->position += this->velocity * elapsedTime;
    }

    void run_animation(double elapsedTime) override
    {
        auto current_animation = ([this]() {
            if (this->start_attack) {
                return ACTIVATE_CANNON;
            }
            if (this->preparing_next_match) {
                return PREPARE_NEXT_MATCH;
            }
            return IDLE_ANIMATION;
        })();
        this->animations.at(current_animation).run(this->renderer, elapsedTime, -this->face, this->position.as_int(), Vector2D<int>{39, 32}, camera_offset);
    }

private:
    void think(double elapsedTime)
    {
        if (!this->start_attack && !this->preparing_next_match) {
            this->think_timeout -= elapsedTime;
            if (this->think_timeout <= 0.) {
                this->start_attack = true;
                this->preparing_next_match = false;
                this->think_timeout = PigWithMatches::DEFAULT_THINK_TIMEOUT;
            }
        }
    }
    
public:
    std::map<int, Animation> animations;
    int face;
    Vector2D<double> position;
    Vector2D<double> old_position;
    Vector2D<double> velocity;
    SDL_Renderer* renderer;
    SDL_Texture* spritesheet;
    double think_timeout;
    bool start_attack;
    bool preparing_next_match;
    Cannon& cannon;
};

#endif
