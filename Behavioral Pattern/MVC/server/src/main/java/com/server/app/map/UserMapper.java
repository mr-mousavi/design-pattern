package com.server.app.map;

import com.server.app.model.User;
import com.server.app.view.UserView;
import org.mapstruct.Mapper;
import org.microdeaf.mapper.annotation.MicrodeafMapper;
import org.microdeaf.mapper.mapstruct.BaseMapper;

@Mapper
@MicrodeafMapper(entity = User.class, view = UserView.class)
public interface UserMapper extends  BaseMapper<User, UserView> {

    UserView toView(User entity);

    User toEntity(UserView view);
}
